.setcpu "65816"
.segment "CODE"
.org $C12F
map_control_0ec12f:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
