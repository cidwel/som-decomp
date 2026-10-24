.setcpu "65816"
.segment "CODE"
.org $1F75
map_control_0d1f75:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
