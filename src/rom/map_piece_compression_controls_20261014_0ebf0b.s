.setcpu "65816"
.segment "CODE"
.org $BF0B
map_control_0ebf0b:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
