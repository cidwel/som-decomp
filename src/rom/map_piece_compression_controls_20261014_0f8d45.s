.setcpu "65816"
.segment "CODE"
.org $8D45
map_control_0f8d45:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
