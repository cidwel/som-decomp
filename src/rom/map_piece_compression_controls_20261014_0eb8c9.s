.setcpu "65816"
.segment "CODE"
.org $B8C9
map_control_0eb8c9:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
