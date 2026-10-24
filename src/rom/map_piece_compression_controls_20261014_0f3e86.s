.setcpu "65816"
.segment "CODE"
.org $3E86
map_control_0f3e86:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
