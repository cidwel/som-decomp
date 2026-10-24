.setcpu "65816"
.segment "CODE"
.org $9127
map_control_0f9127:
    .byte $EA ; backreference distance high bits
    .byte $08 ; distance low bit/count
