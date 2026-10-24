.setcpu "65816"
.segment "CODE"
.org $CAFA
map_control_0ecafa:
    .byte $C3 ; same-value copy count/distance
