; SPC $054E; physical ROM $C30A98; complete native note sequencing.
SBC A,#$D2
ASL A
MOV Y,A
MOV A,!$1429+Y
PUSH A
MOV A,!$1428+Y
PUSH A
MOV A,Y
LSR A
MOV Y,A
MOV A,!$1484+Y
BEQ $056C
