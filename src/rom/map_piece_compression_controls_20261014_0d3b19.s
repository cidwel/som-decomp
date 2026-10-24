.setcpu "65816"
.segment "CODE"
.org $3B19
map_control_0d3b19:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
