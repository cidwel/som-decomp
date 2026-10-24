.setcpu "65816"
.segment "CODE"
.org $3EE4
map_control_0d3ee4:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
