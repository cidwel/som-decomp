.setcpu "65816"
.segment "CODE"
.org $B1C3
map_control_0db1c3:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
