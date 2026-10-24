.setcpu "65816"
.segment "CODE"
.org $B8DE
map_control_0eb8de:
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
