.setcpu "65816"
.segment "CODE"
.org $DDCC
map_control_0eddcc:
    .byte $EA ; backreference distance high bits
    .byte $8A ; distance low bit/count
