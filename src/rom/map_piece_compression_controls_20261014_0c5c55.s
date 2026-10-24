.setcpu "65816"
.segment "CODE"
.org $5C55
map_control_0c5c55:
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
