.setcpu "65816"
.segment "CODE"
.org $AB2B
map_control_0dab2b:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
