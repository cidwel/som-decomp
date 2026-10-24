.setcpu "65816"
.segment "CODE"
.org $0531
map_control_0e0531:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
