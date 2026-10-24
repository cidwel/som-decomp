.setcpu "65816"
.segment "CODE"
.org $CA16
map_control_0fca16:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
