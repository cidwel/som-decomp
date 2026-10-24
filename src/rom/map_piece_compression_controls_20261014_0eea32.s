.setcpu "65816"
.segment "CODE"
.org $EA32
map_control_0eea32:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
