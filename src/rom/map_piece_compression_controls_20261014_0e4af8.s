.setcpu "65816"
.segment "CODE"
.org $4AF8
map_control_0e4af8:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
