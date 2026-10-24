.setcpu "65816"
.segment "CODE"
.org $545F
map_control_0c545f:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
