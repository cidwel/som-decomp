.setcpu "65816"
.segment "CODE"
.org $FCBE
map_control_0ffcbe:
    .byte $C4 ; same-value copy count/distance
