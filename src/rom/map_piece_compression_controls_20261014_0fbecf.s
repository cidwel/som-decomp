.setcpu "65816"
.segment "CODE"
.org $BECF
map_control_0fbecf:
    .byte $D1 ; same-value copy count/distance
