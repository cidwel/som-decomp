.setcpu "65816"
.segment "CODE"
.org $D311
map_control_0dd311:
    .byte $C1 ; same-value copy count/distance
    .byte $DF ; same-value copy count/distance
