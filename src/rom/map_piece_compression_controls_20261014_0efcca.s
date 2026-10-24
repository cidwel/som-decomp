.setcpu "65816"
.segment "CODE"
.org $FCCA
map_control_0efcca:
    .byte $D7 ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
