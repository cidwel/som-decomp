.setcpu "65816"
.segment "CODE"
.org $AB7D
map_control_0dab7d:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
