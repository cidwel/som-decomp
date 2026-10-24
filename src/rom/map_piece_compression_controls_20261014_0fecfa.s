.setcpu "65816"
.segment "CODE"
.org $ECFA
map_control_0fecfa:
    .byte $C3 ; same-value copy count/distance
