.setcpu "65816"
.segment "CODE"
.org $E494
map_control_0ee494:
    .byte $F3 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
