.setcpu "65816"
.segment "CODE"
.org $F520
map_control_0cf520:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
