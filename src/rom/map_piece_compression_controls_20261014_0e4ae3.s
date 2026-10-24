.setcpu "65816"
.segment "CODE"
.org $4AE3
map_control_0e4ae3:
    .byte $C2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
