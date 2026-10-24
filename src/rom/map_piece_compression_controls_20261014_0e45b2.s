.setcpu "65816"
.segment "CODE"
.org $45B2
map_control_0e45b2:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $D2 ; same-value copy count/distance
