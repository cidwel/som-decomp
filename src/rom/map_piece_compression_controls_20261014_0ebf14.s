.setcpu "65816"
.segment "CODE"
.org $BF14
map_control_0ebf14:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
