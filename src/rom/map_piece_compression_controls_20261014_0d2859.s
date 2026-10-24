.setcpu "65816"
.segment "CODE"
.org $2859
map_control_0d2859:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
