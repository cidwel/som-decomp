.setcpu "65816"
.segment "CODE"
.org $6D56
map_control_0c6d56:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
