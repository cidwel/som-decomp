.setcpu "65816"
.segment "CODE"
.org $3FA7
map_control_0d3fa7:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
