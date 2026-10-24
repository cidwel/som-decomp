.setcpu "65816"
.segment "CODE"
.org $854D
map_control_0e854d:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
