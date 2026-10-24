.setcpu "65816"
.segment "CODE"
.org $1473
map_control_0c1473:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
