local $name = InputBox("Name", "Name")

Func replaceFile($file)

$szText = FileRead($file,FileGetSize($file))

$szText = StringReplace($szText, "CLASS_NAME", $name)

FileDelete($file)

FileWrite($file,$szText)

   EndFunc

local $normalDir = "src/" & $name & "/"
local $privateDir = "src/" & $name & "/" & $name & "Private/"

local $cloneDir = "ClassClone/"

DirCreate($normalDir)
DirCreate($privateDir)

FileCopy($cloneDir & "HeaderExample.txt", $normalDir & $name & ".h")
replaceFile($normalDir & $name & ".h")

FileCopy($cloneDir & "SourceExample.txt", $normalDir & $name & ".cpp")
replaceFile($normalDir & $name & ".cpp")

FileCopy($cloneDir & "HeaderPrivateExample.txt", $privateDir & $name & "Private.h")
replaceFile($privateDir & $name & "Private.h")

FileCopy($cloneDir & "SourcePrivateExample.txt", $privateDir & $name & "Private.cpp")
replaceFile($privateDir & $name & "Private.cpp")