.setcpu "65816"
.segment "CODE"
.org $7D14
map_control_0c7d14:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
