.setcpu "65816"
.segment "CODE"
.org $9761
map_control_0f9761:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
