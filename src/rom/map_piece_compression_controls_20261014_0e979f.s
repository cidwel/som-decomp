.setcpu "65816"
.segment "CODE"
.org $979F
map_control_0e979f:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
