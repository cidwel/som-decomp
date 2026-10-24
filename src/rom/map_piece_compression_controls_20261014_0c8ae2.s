.setcpu "65816"
.segment "CODE"
.org $8AE2
map_control_0c8ae2:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
