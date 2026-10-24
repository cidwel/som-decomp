.setcpu "65816"
.segment "CODE"
.org $7293
map_control_0d7293:
    .byte $E8 ; backreference distance high bits
    .byte $95 ; distance low bit/count
