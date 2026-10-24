.setcpu "65816"
.segment "CODE"
.org $E14A
map_control_0fe14a:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
