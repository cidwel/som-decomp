.setcpu "65816"
.segment "CODE"
.org $3ED6
map_control_0d3ed6:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
