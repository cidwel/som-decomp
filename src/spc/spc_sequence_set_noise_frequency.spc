; SPC $0831; physical ROM $C30D7B; native sequence command.
AND A,#$1F
CMP X,#$10
BCS $083B
MOV $C5,A
BRA $0803
MOV $C6,A
BRA $0803
