.setcpu "65816"
.segment "CODE"
.org $6FD2
map_control_0c6fd2:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
