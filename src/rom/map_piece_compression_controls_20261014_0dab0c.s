.setcpu "65816"
.segment "CODE"
.org $AB0C
map_control_0dab0c:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
