.setcpu "65816"
.segment "CODE"
.org $F722
map_control_0cf722:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
