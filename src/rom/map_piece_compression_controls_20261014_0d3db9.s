.setcpu "65816"
.segment "CODE"
.org $3DB9
map_control_0d3db9:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
