.setcpu "65816"
.segment "CODE"
.org $09E7
map_control_0f09e7:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
