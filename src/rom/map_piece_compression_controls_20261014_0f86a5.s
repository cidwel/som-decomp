.setcpu "65816"
.segment "CODE"
.org $86A5
map_control_0f86a5:
    .byte $E8 ; backreference distance high bits
    .byte $72 ; distance low bit/count
