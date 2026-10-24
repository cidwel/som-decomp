.setcpu "65816"
.segment "CODE"
.org $2FB6
map_control_0f2fb6:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
