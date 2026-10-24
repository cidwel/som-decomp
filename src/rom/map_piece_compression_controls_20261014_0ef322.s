.setcpu "65816"
.segment "CODE"
.org $F322
map_control_0ef322:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
