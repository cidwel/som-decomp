.setcpu "65816"
.segment "CODE"
.org $43BC
map_control_0c43bc:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
