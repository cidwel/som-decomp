.setcpu "65816"
.segment "CODE"
.org $F96D
map_control_0ff96d:
    .byte $C1 ; same-value copy count/distance
