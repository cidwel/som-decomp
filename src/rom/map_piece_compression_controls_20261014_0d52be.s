.setcpu "65816"
.segment "CODE"
.org $52BE
map_control_0d52be:
    .byte $D7 ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
