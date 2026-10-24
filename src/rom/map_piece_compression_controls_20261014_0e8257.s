.setcpu "65816"
.segment "CODE"
.org $8257
map_control_0e8257:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
