.setcpu "65816"
.segment "CODE"
.org $2812
map_control_0d2812:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
