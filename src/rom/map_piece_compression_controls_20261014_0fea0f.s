.setcpu "65816"
.segment "CODE"
.org $EA0F
map_control_0fea0f:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
