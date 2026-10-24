.setcpu "65816"
.segment "CODE"
.org $19CF
map_control_0d19cf:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
