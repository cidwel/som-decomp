.setcpu "65816"
.segment "CODE"
.org $3607
map_control_0d3607:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
