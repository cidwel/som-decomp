.setcpu "65816"
.segment "CODE"
.org $09BE
map_control_0e09be:
    .byte $C7 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
