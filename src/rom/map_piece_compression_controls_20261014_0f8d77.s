.setcpu "65816"
.segment "CODE"
.org $8D77
map_control_0f8d77:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
