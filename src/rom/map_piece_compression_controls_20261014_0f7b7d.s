.setcpu "65816"
.segment "CODE"
.org $7B7D
map_control_0f7b7d:
    .byte $EA ; backreference distance high bits
    .byte $87 ; distance low bit/count
