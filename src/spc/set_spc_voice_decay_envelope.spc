; SPC $08BE; physical ROM $C30E08; native instrument control.
AND A,#$07
XCN A
MOV $04,A
MOV A,!$FE80+X
AND A,#$0F
OR A,$04
OR A,#$80
MOV !$FE80+X,A
BRA $08A0
