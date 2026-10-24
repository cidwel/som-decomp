.setcpu "65816"
.segment "CODE"
.org $5D06
map_control_0c5d06:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
