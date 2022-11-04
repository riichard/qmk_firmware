# 2022-11-05
- add layers, check if shift works, and make alternative layers for the keypad

# 2022-11-04
- hid_listen seems to work based on source and makefile. See ~/dev/hid_listen
- logging tends to break when console is enabled outside of keyboard/rules.mk
  file according to github discussions
- now tracing issues based on build file from qmk compile kb c42x_cyberdeck -km
  default
- The idea is to create a one-key keyboard with working console logging
- kint41 works out of the box with logging, copy and match as much as possible
- copy pasted as much as possible. Including layout config. The idea was to get
  the directory/structure to work first. to isolate it from directory structure
  issues. And then change the layout.
  THis seems to be a good basis now. Saving to git. Will now continue to
  carefully change the layout while the console works.
- start with reassigning pins, only active pins are now connected to the
  teensyduino
- keymap layout file is created
- console suddenly unresponsive, compilation works
- compilation had errors, errors fixed. Everything works
- need to redeisgn and remap keys. not sure if going with macros:w


# 2022-08-01
- created c42x_cyberdeck
- console should work, but does not. THis seems to be the only way forward to
  debug
- could not get hid_listen to work on x86 linux. Try again with teensyduino
  install or compile it
- tried to get one joint to work
