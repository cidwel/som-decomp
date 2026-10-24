.setcpu "65816"
.segment "CODE"
.org $F1AC
map_control_0df1ac:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
