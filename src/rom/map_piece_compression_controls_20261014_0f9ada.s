.setcpu "65816"
.segment "CODE"
.org $9ADA
map_control_0f9ada:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
