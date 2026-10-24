.setcpu "65816"
.segment "CODE"
.org $CA7C
map_control_0fca7c:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
