array A = [3] U32
constant a = 0
enum E { X, Y }
struct S { x: U32 }
type T

module M {
  array A = [3] U32
  constant a = 0
  enum E { X, Y }
  struct S { x: U32 }
  type T
} 

port P

passive component C1 {
  array A = [3] U32
  constant a = 0
  enum E { X, Y }
  struct S { x: U32 }
  type T
}

# Placeholders for core F Prime ports
# used in special port instances
module Fw {
  port Cmd
  port CmdReg
  port CmdResponse
  port Log
  port LogText
  port PrmGet
  port PrmSet
  port Time
  port Tlm
}
