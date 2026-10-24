.setcpu "65816"
.segment "CODE"
.org $AB85
map_control_0dab85:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
