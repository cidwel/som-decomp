.setcpu "65816"
.segment "CODE"
.org $AC43
map_control_0fac43:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
