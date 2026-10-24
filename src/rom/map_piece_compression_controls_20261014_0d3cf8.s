.setcpu "65816"
.segment "CODE"
.org $3CF8
map_control_0d3cf8:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
