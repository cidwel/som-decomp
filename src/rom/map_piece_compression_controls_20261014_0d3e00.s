.setcpu "65816"
.segment "CODE"
.org $3E00
map_control_0d3e00:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
