.setcpu "65816"
.segment "CODE"
.org $7CC7
map_control_0c7cc7:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
