.setcpu "65816"
.segment "CODE"
.org $D8D0
map_control_0fd8d0:
    .byte $C5 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $C6 ; same-value copy count/distance
