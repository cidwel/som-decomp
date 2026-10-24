.setcpu "65816"
.segment "CODE"
.org $1CA8
map_control_0e1ca8:
    .byte $D7 ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $F1 ; progressive-copy count
    .byte $C6 ; same-value copy count/distance
