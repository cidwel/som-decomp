; SPC $0FF9; physical ROM $C31543; native high command.
CMP X,#$F0
BCS dispatch_target
CMP X,#$90
BCS ignored
dispatch_target:
MOV A,X
AND A,#$1F
ASL A
MOV Y,A
MOV A,!$14B3+Y
PUSH A
MOV A,!$14B2+Y
PUSH A
ignored:
RET
