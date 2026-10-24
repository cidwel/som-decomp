.setcpu "65816"
.segment "CODE"
.org $88FC
map_control_0f88fc:
    .byte $D7 ; same-value copy count/distance
    .byte $C5 ; same-value copy count/distance
