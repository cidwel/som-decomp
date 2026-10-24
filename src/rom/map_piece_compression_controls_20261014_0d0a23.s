.setcpu "65816"
.segment "CODE"
.org $0A23
map_control_0d0a23:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
