; SPC $08D1; physical ROM $C30E1B; native instrument control.
AND A,#$07
XCN A
ASL A
MOV $04,A
MOV A,!$FE81+X
AND A,#$1F
OR A,$04
MOV !$FE81+X,A
BRA $08A0
