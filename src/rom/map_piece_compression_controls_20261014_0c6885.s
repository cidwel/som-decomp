.setcpu "65816"
.segment "CODE"
.org $6885
map_control_0c6885:
    .byte $DF ; same-value copy count/distance
    .byte $C3 ; same-value copy count/distance
