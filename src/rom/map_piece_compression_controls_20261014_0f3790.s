.setcpu "65816"
.segment "CODE"
.org $3790
map_control_0f3790:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
