.setcpu "65816"
.segment "CODE"
.org $142D
map_control_0f142d:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
