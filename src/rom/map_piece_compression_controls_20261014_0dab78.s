.setcpu "65816"
.segment "CODE"
.org $AB78
map_control_0dab78:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
