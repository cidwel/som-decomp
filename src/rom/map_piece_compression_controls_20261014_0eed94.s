.setcpu "65816"
.segment "CODE"
.org $ED94
map_control_0eed94:
    .byte $E8 ; backreference distance high bits
    .byte $94 ; distance low bit/count
