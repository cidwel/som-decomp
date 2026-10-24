.setcpu "65816"
.segment "CODE"
.org $1283
map_control_0e1283:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
