.setcpu "65816"
.segment "CODE"
.org $3F19
map_control_0d3f19:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
