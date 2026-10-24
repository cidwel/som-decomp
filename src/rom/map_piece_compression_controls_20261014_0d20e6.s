.setcpu "65816"
.segment "CODE"
.org $20E6
map_control_0d20e6:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
