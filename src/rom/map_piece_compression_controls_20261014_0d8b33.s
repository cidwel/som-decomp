.setcpu "65816"
.segment "CODE"
.org $8B33
map_control_0d8b33:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
