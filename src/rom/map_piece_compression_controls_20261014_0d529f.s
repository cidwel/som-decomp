.setcpu "65816"
.segment "CODE"
.org $529F
map_control_0d529f:
    .byte $DF ; same-value copy count/distance
    .byte $C3 ; same-value copy count/distance
