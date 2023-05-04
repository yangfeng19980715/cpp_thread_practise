#! /usr/bin/python

line = str()

code_src = str()

while True:
  print("code:\n{0}\n".format(code_src))
  line = input("input a line cxx code(q or Q to quit):")
  if line == "Q" or line == "q":
    break

  code_src += "\n" + line
  pass