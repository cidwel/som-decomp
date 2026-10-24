.setcpu "65816"
.segment "CODE"
.org $927F
map_control_0c927f:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
