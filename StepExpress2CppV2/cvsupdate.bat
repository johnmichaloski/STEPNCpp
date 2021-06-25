


set cvsroot=:sspi:localhost/cvs_repository


cvs checkout  -l  ./   -d stepncpp


cvs update  Misc.h
cvs update  ExpressUtil.h   
cvs update  ExpressUtil.cpp
cvs update  OutDebug.h 
cvs update  CreateCPPClasses.h 
cvs update  CreateCPPClasses.cpp
cvs update  StepParser.h 
cvs update  StepParser.cpp

pause