.setcpu "65816"
.segment "CODE"
.org $CF03
map_control_0fcf03:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
