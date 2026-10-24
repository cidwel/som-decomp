.setcpu "65816"
.segment "CODE"
.org $CBFF
map_control_0dcbff:
    .byte $C1 ; same-value copy count/distance
