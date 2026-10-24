.setcpu "65816"
.segment "CODE"
.org $10C5
map_control_0e10c5:
    .byte $EA ; backreference distance high bits
    .byte $06 ; distance low bit/count
