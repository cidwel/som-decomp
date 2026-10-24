.setcpu "65816"
.segment "CODE"
.org $3E3F
map_control_0d3e3f:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
