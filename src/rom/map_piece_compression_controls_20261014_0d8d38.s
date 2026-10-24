.setcpu "65816"
.segment "CODE"
.org $8D38
map_control_0d8d38:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
