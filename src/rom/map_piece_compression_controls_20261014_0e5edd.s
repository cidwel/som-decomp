.setcpu "65816"
.segment "CODE"
.org $5EDD
map_control_0e5edd:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
