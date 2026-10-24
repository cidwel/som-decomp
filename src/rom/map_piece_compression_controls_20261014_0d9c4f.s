.setcpu "65816"
.segment "CODE"
.org $9C4F
map_control_0d9c4f:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
