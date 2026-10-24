.setcpu "65816"
.segment "CODE"
.org $4F8F
map_control_0e4f8f:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
