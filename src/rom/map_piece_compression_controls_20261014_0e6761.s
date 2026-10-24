.setcpu "65816"
.segment "CODE"
.org $6761
map_control_0e6761:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
