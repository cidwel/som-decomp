.setcpu "65816"
.segment "CODE"
.org $8245
map_control_0c8245:
    .byte $D2 ; same-value copy count/distance
    .byte $DF ; same-value copy count/distance
    .byte $C5 ; same-value copy count/distance
