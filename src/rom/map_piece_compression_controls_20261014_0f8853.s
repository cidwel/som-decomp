.setcpu "65816"
.segment "CODE"
.org $8853
map_control_0f8853:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
