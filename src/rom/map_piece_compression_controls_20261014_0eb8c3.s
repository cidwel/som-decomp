.setcpu "65816"
.segment "CODE"
.org $B8C3
map_control_0eb8c3:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
