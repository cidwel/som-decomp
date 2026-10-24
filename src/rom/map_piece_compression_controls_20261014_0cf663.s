.setcpu "65816"
.segment "CODE"
.org $F663
map_control_0cf663:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
