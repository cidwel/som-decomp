.setcpu "65816"
.segment "CODE"
.org $2D6E
map_control_0f2d6e:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
