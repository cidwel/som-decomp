.setcpu "65816"
.segment "CODE"
.org $B8CC
map_control_0eb8cc:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
