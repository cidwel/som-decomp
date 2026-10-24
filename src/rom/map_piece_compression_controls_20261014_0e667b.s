.setcpu "65816"
.segment "CODE"
.org $667B
map_control_0e667b:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
