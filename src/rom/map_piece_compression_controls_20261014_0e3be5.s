.setcpu "65816"
.segment "CODE"
.org $3BE5
map_control_0e3be5:
    .byte $DF ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
