.setcpu "65816"
.segment "CODE"
.org $5283
map_control_0d5283:
    .byte $DF ; same-value copy count/distance
    .byte $C3 ; same-value copy count/distance
