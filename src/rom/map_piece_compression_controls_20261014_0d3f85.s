.setcpu "65816"
.segment "CODE"
.org $3F85
map_control_0d3f85:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
