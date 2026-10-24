.setcpu "65816"
.segment "CODE"
.org $7BEA
map_control_0c7bea:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
