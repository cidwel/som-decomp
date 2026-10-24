.setcpu "65816"
.segment "CODE"
.org $3092
map_control_0f3092:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
