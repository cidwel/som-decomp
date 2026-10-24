.setcpu "65816"
.segment "CODE"
.org $0CA7
map_control_0d0ca7:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
