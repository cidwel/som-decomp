.setcpu "65816"
.segment "CODE"
.org $31AA
map_control_0e31aa:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
