.setcpu "65816"
.segment "CODE"
.org $727B
map_control_0e727b:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
