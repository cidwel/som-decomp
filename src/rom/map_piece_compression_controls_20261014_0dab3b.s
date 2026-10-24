.setcpu "65816"
.segment "CODE"
.org $AB3B
map_control_0dab3b:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
