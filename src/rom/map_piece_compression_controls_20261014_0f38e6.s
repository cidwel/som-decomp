.setcpu "65816"
.segment "CODE"
.org $38E6
map_control_0f38e6:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
