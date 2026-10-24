.setcpu "65816"
.segment "CODE"
.org $0BC5
map_control_0d0bc5:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
