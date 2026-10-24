.setcpu "65816"
.segment "CODE"
.org $059C
map_control_0e059c:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
