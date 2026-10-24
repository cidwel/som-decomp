.setcpu "65816"
.segment "CODE"
.org $3174
map_control_0e3174:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
