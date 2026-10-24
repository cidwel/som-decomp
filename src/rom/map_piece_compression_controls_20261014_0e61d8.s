.setcpu "65816"
.segment "CODE"
.org $61D8
map_control_0e61d8:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
