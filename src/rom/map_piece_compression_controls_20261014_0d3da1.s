.setcpu "65816"
.segment "CODE"
.org $3DA1
map_control_0d3da1:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
