.setcpu "65816"
.segment "CODE"
.org $9F4F
map_control_0d9f4f:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
