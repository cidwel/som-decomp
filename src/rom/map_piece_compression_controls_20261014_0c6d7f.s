.setcpu "65816"
.segment "CODE"
.org $6D7F
map_control_0c6d7f:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
