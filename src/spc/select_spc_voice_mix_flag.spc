; SPC $111F; physical ROM $C31669; native high command.
BBC $B4.0,enable_mix
CLR1 $B1.0
BRA dirty_mix
enable_mix:
SET1 $B1.0
dirty_mix:
MOV $C9,#$FF
RET
