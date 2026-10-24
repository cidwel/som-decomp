.setcpu "65816"
.segment "CODE"
.org $21F6
map_control_0c21f6:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
