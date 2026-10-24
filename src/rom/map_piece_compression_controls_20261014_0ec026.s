.setcpu "65816"
.segment "CODE"
.org $C026
map_control_0ec026:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
