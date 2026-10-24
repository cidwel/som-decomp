.setcpu "65816"
.segment "CODE"
.org $76CA
map_control_0e76ca:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
