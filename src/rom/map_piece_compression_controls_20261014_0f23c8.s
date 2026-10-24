.setcpu "65816"
.segment "CODE"
.org $23C8
map_control_0f23c8:
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
