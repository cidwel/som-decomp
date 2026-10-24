.setcpu "65816"
.segment "CODE"
.org $2CEE
map_control_0f2cee:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
