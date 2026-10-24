.setcpu "65816"
.segment "CODE"
.org $76B5
map_control_0e76b5:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
