.setcpu "65816"
.segment "CODE"
.org $4C49
map_control_0d4c49:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
