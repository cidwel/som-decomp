.setcpu "65816"
.segment "CODE"
.org $8AD7
map_control_0e8ad7:
    .byte $EB ; backreference distance high bits
    .byte $91 ; distance low bit/count
