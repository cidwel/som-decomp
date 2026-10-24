.setcpu "65816"
.segment "CODE"
.org $6612
map_control_0c6612:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
