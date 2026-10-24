.setcpu "65816"
.segment "CODE"
.org $41A6
map_control_0d41a6:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
