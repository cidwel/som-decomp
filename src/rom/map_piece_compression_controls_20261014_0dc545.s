.setcpu "65816"
.segment "CODE"
.org $C545
map_control_0dc545:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
