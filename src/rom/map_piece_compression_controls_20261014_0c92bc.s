.setcpu "65816"
.segment "CODE"
.org $92BC
map_control_0c92bc:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
