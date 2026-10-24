.setcpu "65816"
.segment "CODE"
.org $BF02
map_control_0ebf02:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
