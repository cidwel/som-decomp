.setcpu "65816"
.segment "CODE"
.org $3DE9
map_control_0d3de9:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
