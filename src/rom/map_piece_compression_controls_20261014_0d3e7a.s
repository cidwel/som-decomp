.setcpu "65816"
.segment "CODE"
.org $3E7A
map_control_0d3e7a:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
