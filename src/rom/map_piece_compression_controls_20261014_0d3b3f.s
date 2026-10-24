.setcpu "65816"
.segment "CODE"
.org $3B3F
map_control_0d3b3f:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
