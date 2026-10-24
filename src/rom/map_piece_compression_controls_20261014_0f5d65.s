.setcpu "65816"
.segment "CODE"
.org $5D65
map_control_0f5d65:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
