.setcpu "65816"
.segment "CODE"
.org $C01D
map_control_0dc01d:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
