.setcpu "65816"
.segment "CODE"
.org $AB60
map_control_0dab60:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
