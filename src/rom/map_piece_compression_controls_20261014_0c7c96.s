.setcpu "65816"
.segment "CODE"
.org $7C96
map_control_0c7c96:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
