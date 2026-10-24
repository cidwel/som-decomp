.setcpu "65816"
.segment "CODE"
.org $5735
map_control_0d5735:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
