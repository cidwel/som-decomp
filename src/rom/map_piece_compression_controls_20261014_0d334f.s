.setcpu "65816"
.segment "CODE"
.org $334F
map_control_0d334f:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
