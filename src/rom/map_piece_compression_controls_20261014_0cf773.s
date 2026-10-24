.setcpu "65816"
.segment "CODE"
.org $F773
map_control_0cf773:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
