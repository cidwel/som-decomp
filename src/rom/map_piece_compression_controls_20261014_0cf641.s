.setcpu "65816"
.segment "CODE"
.org $F641
map_control_0cf641:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
