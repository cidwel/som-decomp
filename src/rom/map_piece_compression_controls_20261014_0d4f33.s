.setcpu "65816"
.segment "CODE"
.org $4F33
map_control_0d4f33:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
