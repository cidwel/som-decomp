.setcpu "65816"
.segment "CODE"
.org $502E
map_control_0f502e:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
