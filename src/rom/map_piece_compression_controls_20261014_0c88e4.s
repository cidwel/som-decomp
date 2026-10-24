.setcpu "65816"
.segment "CODE"
.org $88E4
map_control_0c88e4:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
