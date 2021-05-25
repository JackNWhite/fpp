package fpp.compiler.codegen

import fpp.compiler.analysis._
import fpp.compiler.ast._
import fpp.compiler.util._

/** ====================================================================== 
 *  Computes the names of the C++ files to generate
 *  Checks for duplicates that would cause a name collision. 
 *  ======================================================================*/
object ComputeCppFiles extends AstStateVisitor {

  type State = Map[String, Option[Location]]

  /** Generated C++ file names */
  object Names {

    /** Constant definitions */
    val constants = "FppConstants"
    
    /** Topology definitions */
    val topology = "Topology"

  }

  override def defComponentAnnotatedNode(
    s: State,
    aNode: Ast.Annotated[AstNode[Ast.DefComponent]]
  ) = {
    val (_, node, _) = aNode
    val data = node.data
    visitList(s, data.members, matchComponentMember)
  }

  override def defConstantAnnotatedNode(
    s: State,
    node: Ast.Annotated[AstNode[Ast.DefConstant]]
  ) = addMappings(s, Names.constants)

  override def defModuleAnnotatedNode(
    s: State,
    aNode: Ast.Annotated[AstNode[Ast.DefModule]]
  ) = {
    val (_, node, _) = aNode
    val data = node.data
    visitList(s, data.members, matchModuleMember)
  }
 
  override def defTopologyAnnotatedNode(
    s: State,
    aNode: Ast.Annotated[AstNode[Ast.DefTopology]]
  ) = addMappings(s, Names.topology)

  override def transUnit(s: State, tu: Ast.TransUnit) =
    visitList(s, tu.members, matchTuMember)

  /** Adds mappings for hpp and cppfiles */
  private def addMappings(s: State, fileName: String, locOpt: Option[Location] = None) = {
    for {
      s <- addHppMapping(s, fileName, locOpt)
      s <- addCppMapping(s, fileName, locOpt)
    }
    yield s
  }

  /** Adds a mapping for an hpp file  */
  private def addHppMapping(s: State, fileName: String, locOpt: Option[Location] = None) =
    addMapping(s, (s"$fileName.hpp" -> locOpt))

  /** Adds a mapping for a cpp file  */
  private def addCppMapping(s: State, fileName: String, locOpt: Option[Location] = None) =
    addMapping(s, (s"$fileName.cpp" -> locOpt))

  /** Adds a mapping for one file */
  private def addMapping(s: State, mapping: (String, Option[Location])) = {
    val (fileName, locOpt) = mapping
    (s.get(fileName), locOpt) match {
      case (Some(Some(prevLoc)), Some(loc)) => Left(CodeGenError.DuplicateCppFile(fileName, loc, prevLoc))
      case _ => Right(s + mapping)
    }
  }

}