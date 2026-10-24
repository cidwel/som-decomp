.setcpu "65816"
.segment "CODE"
.org $3B43
map_control_0e3b43:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
