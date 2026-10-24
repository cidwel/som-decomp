.setcpu "65816"
.segment "CODE"
.org $2384
map_control_0e2384:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
