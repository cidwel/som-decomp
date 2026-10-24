.setcpu "65816"
.segment "CODE"
.org $6DA5
map_control_0e6da5:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
