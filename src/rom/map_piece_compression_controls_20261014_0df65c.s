.setcpu "65816"
.segment "CODE"
.org $F65C
map_control_0df65c:
    .byte $EA ; backreference distance high bits
    .byte $08 ; distance low bit/count
