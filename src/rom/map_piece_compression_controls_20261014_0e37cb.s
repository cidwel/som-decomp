.setcpu "65816"
.segment "CODE"
.org $37CB
map_control_0e37cb:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
