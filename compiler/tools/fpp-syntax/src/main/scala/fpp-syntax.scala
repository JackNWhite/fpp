package fpp.compiler

import fpp.compiler.analysis._
import fpp.compiler.ast._
import fpp.compiler.codegen._
import fpp.compiler.syntax._
import fpp.compiler.transform._
import fpp.compiler.util._
import scopt.OParser

object FPPSyntax {

  case class Options(
    ast: Boolean = false,
    include: Boolean = false,
    files: List[File] = List()
  )

  def command(options: Options) = {
    Error.setTool(Tool(name))
    val files = options.files.reverse match {
      case Nil => List(File.StdIn)
      case list => list
    }
    val result = Result.seq(
      Result.map(files, Parser.parseFile (Parser.transUnit) (None) _),
      List(resolveIncludes (options) _, printAst (options) _)
    )
    result match {
      case Left(error) => {
        error.print
        errorExit
      }
      case _ => ()
    }
  }

  def errorExit = System.exit(1)

  def main(args: Array[String]) = {
    OParser.parse(oparser, args, Options()) match {
      case Some(options) => command(options)
      case None => errorExit
    }
  }

  def printAst(options: Options)(tul: List[Ast.TransUnit]): Result.Result[List[Ast.TransUnit]] = {
    options.ast match {
      case true => {
        val lines = tul.map(AstWriter.transUnit).flatten
        lines.map(Line.write(Line.stdout) _)
      }
      case false => ()
    }
    Right(tul)
  }

  def resolveIncludes(options: Options)(tul: List[Ast.TransUnit]): Result.Result[List[Ast.TransUnit]] = {
    options.include match {
      case true => for { 
        result <- ResolveSpecInclude.transformList(
          Analysis(),
          tul, 
          ResolveSpecInclude.transUnit
        )
      } yield result._2
      case false => Right(tul)
    }
  }

  val builder = OParser.builder[Options]

  val name = "fpp-syntax"

  val oparser = {
    import builder._
    OParser.sequence(
      programName(name),
      head(name, Version.v),
      opt[Unit]('a', "ast")
        .action((_, c) => c.copy(ast = true))
        .text("print the abstract syntax tree (ast)"),
      opt[Unit]('i', "include")
        .action((_, c) => c.copy(include = true))
        .text("resolve include specifiers"),
      help('h', "help").text("print this message and exit"),
      arg[String]("file ...")
        .unbounded()
        .optional()
        .action((f, c) => c.copy(files = File.fromString(f) :: c.files))
        .text("input files"),
    )
  }

}
