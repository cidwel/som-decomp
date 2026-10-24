.setcpu "65816"
.segment "CODE"
.org $82FD
map_control_0e82fd:
    .byte $C9 ; same-value copy count/distance
    .byte $D4 ; same-value copy count/distance
