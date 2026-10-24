.setcpu "65816"
.segment "CODE"
.org $1282
map_control_0d1282:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
