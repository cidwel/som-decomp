.setcpu "65816"
.segment "CODE"
.org $3E95
map_control_0d3e95:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
