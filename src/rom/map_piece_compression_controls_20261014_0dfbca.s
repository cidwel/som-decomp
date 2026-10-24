.setcpu "65816"
.segment "CODE"
.org $FBCA
map_control_0dfbca:
    .byte $C2 ; same-value copy count/distance
