.setcpu "65816"
.segment "CODE"
.org $0360
map_control_0e0360:
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
