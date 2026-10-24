.setcpu "65816"
.segment "CODE"
.org $4DB2
map_control_0d4db2:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
