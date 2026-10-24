.setcpu "65816"
.segment "CODE"
.org $09FB
map_control_0f09fb:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
