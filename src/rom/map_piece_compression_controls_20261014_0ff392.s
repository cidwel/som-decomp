.setcpu "65816"
.segment "CODE"
.org $F392
map_control_0ff392:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
