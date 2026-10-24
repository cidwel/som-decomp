.setcpu "65816"
.segment "CODE"
.org $3B3E
map_control_0f3b3e:
    .byte $C2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
