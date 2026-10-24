.setcpu "65816"
.segment "CODE"
.org $3989
map_control_0f3989:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
