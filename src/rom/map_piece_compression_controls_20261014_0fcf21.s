.setcpu "65816"
.segment "CODE"
.org $CF21
map_control_0fcf21:
    .byte $C6 ; same-value copy count/distance
