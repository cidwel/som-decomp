.setcpu "65816"
.segment "CODE"
.org $1F1B
map_control_0d1f1b:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
