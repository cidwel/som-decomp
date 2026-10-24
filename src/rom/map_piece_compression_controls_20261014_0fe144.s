.setcpu "65816"
.segment "CODE"
.org $E144
map_control_0fe144:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
