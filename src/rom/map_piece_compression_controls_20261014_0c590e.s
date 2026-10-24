.setcpu "65816"
.segment "CODE"
.org $590E
map_control_0c590e:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
