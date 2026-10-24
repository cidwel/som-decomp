.setcpu "65816"
.segment "CODE"
.org $DE7D
map_control_0fde7d:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
