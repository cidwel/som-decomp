.setcpu "65816"
.segment "CODE"
.org $65B8
map_control_0d65b8:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
