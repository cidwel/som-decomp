.setcpu "65816"
.segment "CODE"
.org $F488
map_control_0ff488:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
