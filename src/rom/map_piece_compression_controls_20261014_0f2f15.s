.setcpu "65816"
.segment "CODE"
.org $2F15
map_control_0f2f15:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
