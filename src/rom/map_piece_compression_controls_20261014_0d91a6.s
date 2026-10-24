.setcpu "65816"
.segment "CODE"
.org $91A6
map_control_0d91a6:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
