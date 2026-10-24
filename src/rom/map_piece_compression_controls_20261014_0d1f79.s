.setcpu "65816"
.segment "CODE"
.org $1F79
map_control_0d1f79:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
