.setcpu "65816"
.segment "CODE"
.org $2FD9
map_control_0e2fd9:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
