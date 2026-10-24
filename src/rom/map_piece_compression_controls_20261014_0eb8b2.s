.setcpu "65816"
.segment "CODE"
.org $B8B2
map_control_0eb8b2:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
