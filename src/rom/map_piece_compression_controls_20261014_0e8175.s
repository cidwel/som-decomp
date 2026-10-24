.setcpu "65816"
.segment "CODE"
.org $8175
map_control_0e8175:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
