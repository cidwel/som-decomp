.setcpu "65816"
.segment "CODE"
.org $D93F
map_control_0dd93f:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
