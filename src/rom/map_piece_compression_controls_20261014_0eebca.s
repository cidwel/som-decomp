.setcpu "65816"
.segment "CODE"
.org $EBCA
map_control_0eebca:
    .byte $C1 ; same-value copy count/distance
