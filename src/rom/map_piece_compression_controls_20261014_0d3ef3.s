.setcpu "65816"
.segment "CODE"
.org $3EF3
map_control_0d3ef3:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
