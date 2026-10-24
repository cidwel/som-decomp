.setcpu "65816"
.segment "CODE"
.org $9E77
map_control_0d9e77:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
