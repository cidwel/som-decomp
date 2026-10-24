.setcpu "65816"
.segment "CODE"
.org $2939
map_control_0d2939:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
