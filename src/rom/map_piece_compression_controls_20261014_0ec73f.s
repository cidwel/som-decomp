.setcpu "65816"
.segment "CODE"
.org $C73F
map_control_0ec73f:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
