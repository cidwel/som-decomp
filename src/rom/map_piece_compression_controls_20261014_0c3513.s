.setcpu "65816"
.segment "CODE"
.org $3513
map_control_0c3513:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
