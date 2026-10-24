.setcpu "65816"
.segment "CODE"
.org $9F77
map_control_0f9f77:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
