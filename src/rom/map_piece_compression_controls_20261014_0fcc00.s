.setcpu "65816"
.segment "CODE"
.org $CC00
map_control_0fcc00:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
