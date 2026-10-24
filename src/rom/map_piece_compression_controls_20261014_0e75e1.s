.setcpu "65816"
.segment "CODE"
.org $75E1
map_control_0e75e1:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
