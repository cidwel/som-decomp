.setcpu "65816"
.segment "CODE"
.org $CA1F
map_control_0fca1f:
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
