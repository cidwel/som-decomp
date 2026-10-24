.setcpu "65816"
.segment "CODE"
.org $0D7F
map_control_0d0d7f:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
