.setcpu "65816"
.segment "CODE"
.org $60EC
map_control_0e60ec:
    .byte $C1 ; same-value copy count/distance
