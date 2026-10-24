.setcpu "65816"
.segment "CODE"
.org $3BD0
map_control_0d3bd0:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
