.setcpu "65816"
.segment "CODE"
.org $073C
map_control_0f073c:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
