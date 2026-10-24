.setcpu "65816"
.segment "CODE"
.org $1737
map_control_0c1737:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
