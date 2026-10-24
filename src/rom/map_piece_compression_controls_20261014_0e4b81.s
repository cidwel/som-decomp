.setcpu "65816"
.segment "CODE"
.org $4B81
map_control_0e4b81:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
