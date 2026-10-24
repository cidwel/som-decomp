.setcpu "65816"
.segment "CODE"
.org $20D8
map_control_0d20d8:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
