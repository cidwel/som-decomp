.setcpu "65816"
.segment "CODE"
.org $4F48
map_control_0d4f48:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
