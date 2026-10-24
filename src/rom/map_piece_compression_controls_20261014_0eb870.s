.setcpu "65816"
.segment "CODE"
.org $B870
map_control_0eb870:
    .byte $E8 ; backreference distance high bits
    .byte $BD ; distance low bit/count
