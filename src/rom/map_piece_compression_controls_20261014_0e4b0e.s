.setcpu "65816"
.segment "CODE"
.org $4B0E
map_control_0e4b0e:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
