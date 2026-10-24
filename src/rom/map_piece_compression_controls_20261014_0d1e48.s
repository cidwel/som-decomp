.setcpu "65816"
.segment "CODE"
.org $1E48
map_control_0d1e48:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
