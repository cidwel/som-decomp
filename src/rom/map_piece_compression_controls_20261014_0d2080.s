.setcpu "65816"
.segment "CODE"
.org $2080
map_control_0d2080:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
