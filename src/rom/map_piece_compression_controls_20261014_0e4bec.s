.setcpu "65816"
.segment "CODE"
.org $4BEC
map_control_0e4bec:
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
