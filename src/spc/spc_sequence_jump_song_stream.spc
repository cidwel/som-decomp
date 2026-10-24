; SPC $0905; physical ROM $C30E4F; native sequence command.
MOV Y,A
CALL !$0562
CMP X,#$10
BCS $0916
MOV A,Y
MOV Y,$04
ADDW YA,$06
MOV $0C+X,A
MOV $0D+X,Y
RET
