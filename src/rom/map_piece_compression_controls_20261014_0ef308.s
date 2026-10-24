.setcpu "65816"
.segment "CODE"
.org $F308
map_control_0ef308:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
