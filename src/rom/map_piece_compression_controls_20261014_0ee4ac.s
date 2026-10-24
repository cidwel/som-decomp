.setcpu "65816"
.segment "CODE"
.org $E4AC
map_control_0ee4ac:
    .byte $F3 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
