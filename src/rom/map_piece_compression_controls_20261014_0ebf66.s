.setcpu "65816"
.segment "CODE"
.org $BF66
map_control_0ebf66:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
