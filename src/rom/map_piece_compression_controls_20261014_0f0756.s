.setcpu "65816"
.segment "CODE"
.org $0756
map_control_0f0756:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
