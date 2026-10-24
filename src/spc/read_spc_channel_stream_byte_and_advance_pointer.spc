; SPC $0562; physical ROM $C30AAC; sequencer dependency.
MOV A,[$0C+X]
MOV $04,A
INC $0C+X
BNE $056C
INC $0D+X
RET
