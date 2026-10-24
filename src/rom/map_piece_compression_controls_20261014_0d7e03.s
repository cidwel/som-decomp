.setcpu "65816"
.segment "CODE"
.org $7E03
map_control_0d7e03:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
