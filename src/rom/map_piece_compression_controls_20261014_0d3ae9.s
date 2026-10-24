.setcpu "65816"
.segment "CODE"
.org $3AE9
map_control_0d3ae9:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
