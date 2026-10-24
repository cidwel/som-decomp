.setcpu "65816"
.segment "CODE"
.org $1FA7
map_control_0c1fa7:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
