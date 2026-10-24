.setcpu "65816"
.segment "CODE"
.org $31EC
map_control_0e31ec:
    .byte $C1 ; same-value copy count/distance
    .byte $DF ; same-value copy count/distance
    .byte $C4 ; same-value copy count/distance
