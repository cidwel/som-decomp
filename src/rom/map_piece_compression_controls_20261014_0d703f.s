.setcpu "65816"
.segment "CODE"
.org $703F
map_control_0d703f:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
