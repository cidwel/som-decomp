.setcpu "65816"
.segment "CODE"
.org $DCCA
map_control_0ddcca:
    .byte $C1 ; same-value copy count/distance
    .byte $DC ; same-value copy count/distance
