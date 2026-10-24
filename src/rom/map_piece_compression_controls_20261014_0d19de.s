.setcpu "65816"
.segment "CODE"
.org $19DE
map_control_0d19de:
    .byte $E8 ; backreference distance high bits
    .byte $9C ; distance low bit/count
