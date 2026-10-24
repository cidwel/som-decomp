.setcpu "65816"
.segment "CODE"
.org $AB0F
map_control_0dab0f:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
