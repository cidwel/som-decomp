.setcpu "65816"
.segment "CODE"
.org $7D90
map_control_0c7d90:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
