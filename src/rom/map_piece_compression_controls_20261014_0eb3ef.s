.setcpu "65816"
.segment "CODE"
.org $B3EF
map_control_0eb3ef:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
