.setcpu "65816"
.segment "CODE"
.org $AFBC
map_control_0eafbc:
    .byte $C1 ; same-value copy count/distance
