package fpp.compiler.codegen

import fpp.compiler.analysis._
import fpp.compiler.util._

/** C++ Writer state */
case class CppWriterState(
  /** The result of semantic analysis */
  a: Analysis,
  /** The output directory */
  dir: String,
  /** The include guard prefix */
  guardPrefix: Option[String],
  /** The list of include path prefixes */
  pathPrefixes: List[String],
  /** The default string size */
  defaultStringSize: Int,
  /** The set of C++ file names */
  fileNames: Set[String] = Set()
) {

  /** Adds the component name prefix to a name.
   *  This is to work around the fact that we can't declare
   *  constants inside component classes, because we are using
   *  F Prime XML to generate the component classes. */
  def addComponentNamePrefix(symbol: Symbol): String = {
    val name = symbol.getUnqualifiedName
    a.parentSymbolMap.get(symbol) match {
      case Some(componentSymbol: Symbol.Component) =>
        val componentName = componentSymbol.getUnqualifiedName
        s"${componentName}_$name"
      case _ => name
    }
  }

  /** Add .cpp and .hpp file names */
  def addFileNames(baseName: String): CppWriterState =
    this.copy(fileNames = fileNames + s"$baseName.cpp" + s"$baseName.hpp")

  /** Removes the longest prefix from a Java path */
  def removeLongestPathPrefix(path: File.JavaPath): File.JavaPath =
    File.removeLongestPrefix(pathPrefixes)(path)

  /** Gets the relative path for a file */
  def getRelativePath(fileName: String): File.JavaPath = {
    val path = java.nio.file.Paths.get(fileName).toAbsolutePath.normalize
    removeLongestPathPrefix(path)
  }

  /** Constructs an include guard from the prefix and a name */
  def includeGuardFromPrefix(name: String) = {
    val guard = guardPrefix match {
      case Some(s) => s"${s}_$name"
      case None => name
    }
    s"${guard}_HPP"
  }

  /** Constructs an include guard from the enclosing namespace and a name */
  def includeGuardFromNamespace(name: String) = {
    val guard = a.scopeNameList.reverse.mkString("_") match {
      case "" => name
      case prefix => s"${prefix}_$name"
    }
    s"${guard}_HPP"
  }

}
