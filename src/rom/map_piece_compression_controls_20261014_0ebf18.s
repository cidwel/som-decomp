.setcpu "65816"
.segment "CODE"
.org $BF18
map_control_0ebf18:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
