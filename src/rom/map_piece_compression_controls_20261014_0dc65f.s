.setcpu "65816"
.segment "CODE"
.org $C65F
map_control_0dc65f:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
