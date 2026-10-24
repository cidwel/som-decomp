.setcpu "65816"
.segment "CODE"
.org $3E34
map_control_0d3e34:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
