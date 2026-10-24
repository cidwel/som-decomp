.setcpu "65816"
.segment "CODE"
.org $20B2
map_control_0d20b2:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
