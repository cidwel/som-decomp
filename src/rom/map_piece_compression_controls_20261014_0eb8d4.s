.setcpu "65816"
.segment "CODE"
.org $B8D4
map_control_0eb8d4:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
