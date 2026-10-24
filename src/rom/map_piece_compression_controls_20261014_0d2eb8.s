.setcpu "65816"
.segment "CODE"
.org $2EB8
map_control_0d2eb8:
    .byte $E9 ; backreference distance high bits
    .byte $06 ; distance low bit/count
