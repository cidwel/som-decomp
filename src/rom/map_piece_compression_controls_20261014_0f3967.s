.setcpu "65816"
.segment "CODE"
.org $3967
map_control_0f3967:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
