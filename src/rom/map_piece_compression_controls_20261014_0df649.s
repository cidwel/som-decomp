.setcpu "65816"
.segment "CODE"
.org $F649
map_control_0df649:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
