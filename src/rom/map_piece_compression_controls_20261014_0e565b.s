.setcpu "65816"
.segment "CODE"
.org $565B
map_control_0e565b:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
