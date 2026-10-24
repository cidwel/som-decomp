.setcpu "65816"
.segment "CODE"
.org $48D1
map_control_0e48d1:
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
