.setcpu "65816"
.segment "CODE"
.org $806D
map_control_0d806d:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
