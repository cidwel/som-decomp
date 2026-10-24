.setcpu "65816"
.segment "CODE"
.org $52E5
map_control_0e52e5:
    .byte $EC ; backreference distance high bits
    .byte $09 ; distance low bit/count
