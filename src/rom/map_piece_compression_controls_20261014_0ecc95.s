.setcpu "65816"
.segment "CODE"
.org $CC95
map_control_0ecc95:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
