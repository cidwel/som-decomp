.setcpu "65816"
.segment "CODE"
.org $B630
map_control_0fb630:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
