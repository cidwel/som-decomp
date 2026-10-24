.setcpu "65816"
.segment "CODE"
.org $B8A8
map_control_0eb8a8:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
