.setcpu "65816"
.segment "CODE"
.org $AB38
map_control_0dab38:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
