.setcpu "65816"
.segment "CODE"
.org $8376
map_control_0d8376:
    .byte $E8 ; backreference distance high bits
    .byte $34 ; distance low bit/count
