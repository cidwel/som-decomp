.setcpu "65816"
.segment "CODE"
.org $7D26
map_control_0c7d26:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
