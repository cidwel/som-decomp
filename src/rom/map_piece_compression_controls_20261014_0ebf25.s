.setcpu "65816"
.segment "CODE"
.org $BF25
map_control_0ebf25:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
