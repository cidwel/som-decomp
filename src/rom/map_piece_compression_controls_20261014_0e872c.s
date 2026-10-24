.setcpu "65816"
.segment "CODE"
.org $872C
map_control_0e872c:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
