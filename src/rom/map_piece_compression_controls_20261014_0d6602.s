.setcpu "65816"
.segment "CODE"
.org $6602
map_control_0d6602:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
