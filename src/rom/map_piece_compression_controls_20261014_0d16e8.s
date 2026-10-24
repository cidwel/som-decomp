.setcpu "65816"
.segment "CODE"
.org $16E8
map_control_0d16e8:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
