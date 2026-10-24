.setcpu "65816"
.segment "CODE"
.org $4A22
map_control_0d4a22:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
