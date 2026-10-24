.setcpu "65816"
.segment "CODE"
.org $7CC0
map_control_0c7cc0:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
