.setcpu "65816"
.segment "CODE"
.org $213F
map_control_0d213f:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
