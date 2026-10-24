.setcpu "65816"
.segment "CODE"
.org $34F3
map_control_0d34f3:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
