.setcpu "65816"
.segment "CODE"
.org $7A9F
map_control_0c7a9f:
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
