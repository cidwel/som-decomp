.setcpu "65816"
.segment "CODE"
.org $94DA
map_control_0f94da:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
