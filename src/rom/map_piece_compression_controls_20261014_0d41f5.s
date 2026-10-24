.setcpu "65816"
.segment "CODE"
.org $41F5
map_control_0d41f5:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
