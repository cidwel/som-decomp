.setcpu "65816"
.segment "CODE"
.org $1F1D
map_control_0e1f1d:
    .byte $D7 ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
