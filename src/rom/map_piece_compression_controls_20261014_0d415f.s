.setcpu "65816"
.segment "CODE"
.org $415F
map_control_0d415f:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
