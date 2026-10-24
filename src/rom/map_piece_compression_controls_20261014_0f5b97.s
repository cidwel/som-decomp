.setcpu "65816"
.segment "CODE"
.org $5B97
map_control_0f5b97:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
