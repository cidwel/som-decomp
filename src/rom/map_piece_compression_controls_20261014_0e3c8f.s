.setcpu "65816"
.segment "CODE"
.org $3C8F
map_control_0e3c8f:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
