.setcpu "65816"
.segment "CODE"
.org $AB63
map_control_0dab63:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
