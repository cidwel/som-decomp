.setcpu "65816"
.segment "CODE"
.org $BC83
map_control_0fbc83:
    .byte $E9 ; backreference distance high bits
    .byte $08 ; distance low bit/count
