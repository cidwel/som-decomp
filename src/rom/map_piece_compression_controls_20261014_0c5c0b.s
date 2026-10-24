.setcpu "65816"
.segment "CODE"
.org $5C0B
map_control_0c5c0b:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
