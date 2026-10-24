.setcpu "65816"
.segment "CODE"
.org $DECF
map_control_0fdecf:
    .byte $C1 ; same-value copy count/distance
