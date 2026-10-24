.setcpu "65816"
.segment "CODE"
.org $2815
map_control_0f2815:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
