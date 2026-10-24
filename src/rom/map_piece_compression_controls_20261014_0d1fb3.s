.setcpu "65816"
.segment "CODE"
.org $1FB3
map_control_0d1fb3:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
