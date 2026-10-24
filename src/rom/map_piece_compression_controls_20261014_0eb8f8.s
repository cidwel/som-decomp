.setcpu "65816"
.segment "CODE"
.org $B8F8
map_control_0eb8f8:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
