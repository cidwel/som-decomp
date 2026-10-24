; SPC $0883; physical ROM $C30DCD; native instrument control.
MOV Y,$5D+X
MOV A,X
XCN A
LSR A
OR A,#$04
MOV $F2,A
MOV $F3,Y
BRA $08A0
