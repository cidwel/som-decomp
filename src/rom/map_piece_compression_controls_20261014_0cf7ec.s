.setcpu "65816"
.segment "CODE"
.org $F7EC
map_control_0cf7ec:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
