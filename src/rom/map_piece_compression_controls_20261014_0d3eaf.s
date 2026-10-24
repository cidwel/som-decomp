.setcpu "65816"
.segment "CODE"
.org $3EAF
map_control_0d3eaf:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
