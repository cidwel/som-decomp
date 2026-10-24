.setcpu "65816"
.segment "CODE"
.org $3E4B
map_control_0d3e4b:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
