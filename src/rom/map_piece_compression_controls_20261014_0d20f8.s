.setcpu "65816"
.segment "CODE"
.org $20F8
map_control_0d20f8:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
