.setcpu "65816"
.segment "CODE"
.org $573B
map_control_0e573b:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
