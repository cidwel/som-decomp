.setcpu "65816"
.segment "CODE"
.org $7892
map_control_0e7892:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
