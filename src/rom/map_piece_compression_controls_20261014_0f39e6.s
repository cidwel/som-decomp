.setcpu "65816"
.segment "CODE"
.org $39E6
map_control_0f39e6:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
