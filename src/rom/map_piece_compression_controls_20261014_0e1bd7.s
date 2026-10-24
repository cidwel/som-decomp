.setcpu "65816"
.segment "CODE"
.org $1BD7
map_control_0e1bd7:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $74 ; distance low bit/count
