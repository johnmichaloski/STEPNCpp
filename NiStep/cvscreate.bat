; Creating a local cvs archive
; 1) import the current directory and subdirectories with cvs import
;    use folder name as the cvs modules -> Nistep=>Nistep
; 2) delete all in Nistep folder then check out the folders from the folder above  cvs co nistep 
;    You should have a copy of all your stuff.
; 3) now you can commit directories from the directory above this one..



set cvsroot=:sspi:localhost/stepnc_repository
cvs import -d -m "Initial STEPNC++ COM Files" NiStep NIST start 


pause