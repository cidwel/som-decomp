.setcpu "65816"
.segment "CODE"
.org $4EBF
map_control_0e4ebf:
    .byte $F1 ; progressive-copy count
    .byte $C5 ; same-value copy count/distance
