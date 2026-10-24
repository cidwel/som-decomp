.setcpu "65816"
.segment "CODE"
.org $DAB0
map_control_0edab0:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
