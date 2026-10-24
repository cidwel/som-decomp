.setcpu "65816"
.segment "CODE"
.org $9651
map_control_0e9651:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
