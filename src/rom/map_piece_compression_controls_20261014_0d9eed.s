.setcpu "65816"
.segment "CODE"
.org $9EED
map_control_0d9eed:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
