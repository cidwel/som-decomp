MOV A,$8B
BEQ second_fade
DEC $8B
MOVW YA,$87
ADDW YA,$83
CMP Y,$84
MOVW $83,YA
BEQ second_fade
OR $C9,$AD
second_fade:
MOV A,$97
BEQ third_fade
DEC $97
MOVW YA,$93
ADDW YA,$8F
MOVW $8F,YA
third_fade:
MOV A,$A3
BEQ finished
DEC $A3
MOVW YA,$9F
ADDW YA,$9B
CMP Y,$9C
MOVW $9B,YA
BEQ finished
OR $CA,$AD
finished:
RET
