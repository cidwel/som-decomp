.setcpu "65816"
.segment "CODE"
.org $2385
map_control_0d2385:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
