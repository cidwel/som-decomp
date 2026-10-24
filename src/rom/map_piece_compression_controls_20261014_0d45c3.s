.setcpu "65816"
.segment "CODE"
.org $45C3
map_control_0d45c3:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
