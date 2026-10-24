.setcpu "65816"
.segment "CODE"
.org $B92F
map_control_0eb92f:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
