package fpp.compiler.tools

import fpp.compiler.codegen._
import fpp.compiler.util._
import scopt.OParser

object FPPFromXml {

  case class Options(
    files: List[File] = Nil,
  )

  def command(options: Options): Result.Result[Unit] = {
    for {
      xmlFiles <- Result.map(options.files, parseXmlFile)
      lines <- XmlFppWriter.writeFileList(xmlFiles)
    }
    yield lines.map(Line.write(Line.stdout) _)
  }

  def parseXmlFile(file: File): Result.Result[XmlFppWriter.File] = {
    for {
      elem <- try {
        Right(scala.xml.XML.loadFile(file.toString))
      }
      catch {
        case e: Exception => Left(XmlError.ParseError(file.toString, e.toString))
      }
    }
    yield XmlFppWriter.File(file.toString, elem)
  }

  def errorExit = System.exit(1)

  def main(args: Array[String]) = {
    Error.setTool(Tool(name))
    OParser.parse(oparser, args, Options()) match {
      case Some(options) => command(options) match {
        case Left(error) => {
          error.print
          errorExit
        }
        case _ => ()
      }
      case None => errorExit
    }
  }

  val builder = OParser.builder[Options]

  val name = "fpp-from-xml"

  val oparser = {
    import builder._
    OParser.sequence(
      programName(name),
      head(name, Version.v),
      help('h', "help").text("print this message and exit"),
      arg[String]("file ...")
        .unbounded()
        .action((f, c) => c.copy(files = File.fromString(f) :: c.files))
        .text("files to translate"),
    )
  }

}
