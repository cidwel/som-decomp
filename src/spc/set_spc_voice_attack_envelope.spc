; SPC $0890; physical ROM $C30DDA; native instrument control.
AND A,#$0F
MOV $04,A
MOV A,!$FE80+X
AND A,#$70
OR A,$04
OR A,#$80
MOV !$FE80+X,A
