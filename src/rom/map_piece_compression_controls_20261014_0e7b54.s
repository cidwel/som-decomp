.setcpu "65816"
.segment "CODE"
.org $7B54
map_control_0e7b54:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
