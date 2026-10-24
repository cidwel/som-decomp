.setcpu "65816"
.segment "CODE"
.org $10BC
map_control_0e10bc:
    .byte $EF ; backreference distance high bits
    .byte $07 ; distance low bit/count
