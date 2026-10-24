.setcpu "65816"
.segment "CODE"
.org $B874
map_control_0eb874:
    .byte $E8 ; backreference distance high bits
    .byte $BD ; distance low bit/count
