.setcpu "65816"
.segment "CODE"
.org $90C5
map_control_0f90c5:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
