.setcpu "65816"
.segment "CODE"
.org $2552
map_control_0d2552:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
