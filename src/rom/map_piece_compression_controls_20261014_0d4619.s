.setcpu "65816"
.segment "CODE"
.org $4619
map_control_0d4619:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
