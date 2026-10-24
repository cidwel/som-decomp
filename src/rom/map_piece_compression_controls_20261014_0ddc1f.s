.setcpu "65816"
.segment "CODE"
.org $DC1F
map_control_0ddc1f:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
