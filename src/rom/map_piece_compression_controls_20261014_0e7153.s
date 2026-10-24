.setcpu "65816"
.segment "CODE"
.org $7153
map_control_0e7153:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
