.setcpu "65816"
.segment "CODE"
.org $AB82
map_control_0dab82:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
