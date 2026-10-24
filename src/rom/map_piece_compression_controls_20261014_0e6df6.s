.setcpu "65816"
.segment "CODE"
.org $6DF6
map_control_0e6df6:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
