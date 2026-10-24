.setcpu "65816"
.segment "CODE"
.org $2210
map_control_0e2210:
    .byte $EC ; backreference distance high bits
    .byte $90 ; distance low bit/count
