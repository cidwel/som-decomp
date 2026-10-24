.setcpu "65816"
.segment "CODE"
.org $8D66
map_control_0f8d66:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
