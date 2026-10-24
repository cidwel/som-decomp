.setcpu "65816"
.segment "CODE"
.org $BEC6
map_control_0ebec6:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
