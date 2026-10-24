.setcpu "65816"
.segment "CODE"
.org $2777
map_control_0f2777:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
