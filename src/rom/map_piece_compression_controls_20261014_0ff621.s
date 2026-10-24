.setcpu "65816"
.segment "CODE"
.org $F621
map_control_0ff621:
    .byte $C6 ; same-value copy count/distance
