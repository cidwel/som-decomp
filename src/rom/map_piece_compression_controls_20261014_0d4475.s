.setcpu "65816"
.segment "CODE"
.org $4475
map_control_0d4475:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
