.setcpu "65816"
.segment "CODE"
.org $77AE
map_control_0e77ae:
    .byte $C1 ; same-value copy count/distance
    .byte $DF ; same-value copy count/distance
