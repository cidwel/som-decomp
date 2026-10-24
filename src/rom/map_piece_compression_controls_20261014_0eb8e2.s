.setcpu "65816"
.segment "CODE"
.org $B8E2
map_control_0eb8e2:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
