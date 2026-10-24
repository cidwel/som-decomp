.setcpu "65816"
.segment "CODE"
.org $ABAD
map_control_0fabad:
    .byte $C4 ; same-value copy count/distance
