.setcpu "65816"
.segment "CODE"
.org $F48F
map_control_0ef48f:
    .byte $ED ; backreference distance high bits
    .byte $09 ; distance low bit/count
