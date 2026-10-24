.setcpu "65816"
.segment "CODE"
.org $20D0
map_control_0d20d0:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
