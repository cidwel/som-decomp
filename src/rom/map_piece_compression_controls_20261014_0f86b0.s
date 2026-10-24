.setcpu "65816"
.segment "CODE"
.org $86B0
map_control_0f86b0:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
