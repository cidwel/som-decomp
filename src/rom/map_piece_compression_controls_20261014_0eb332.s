.setcpu "65816"
.segment "CODE"
.org $B332
map_control_0eb332:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
