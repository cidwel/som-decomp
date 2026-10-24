.setcpu "65816"
.segment "CODE"
.org $6F94
map_control_0f6f94:
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
