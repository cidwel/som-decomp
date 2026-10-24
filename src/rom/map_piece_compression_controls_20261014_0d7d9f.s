.setcpu "65816"
.segment "CODE"
.org $7D9F
map_control_0d7d9f:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
