.setcpu "65816"
.segment "CODE"
.org $94D8
map_control_0d94d8:
    .byte $EF ; backreference distance high bits
    .byte $09 ; distance low bit/count
