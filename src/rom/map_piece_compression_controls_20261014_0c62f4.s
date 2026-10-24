.setcpu "65816"
.segment "CODE"
.org $62F4
map_control_0c62f4:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
