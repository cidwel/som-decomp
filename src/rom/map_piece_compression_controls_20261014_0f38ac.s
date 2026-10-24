.setcpu "65816"
.segment "CODE"
.org $38AC
map_control_0f38ac:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
