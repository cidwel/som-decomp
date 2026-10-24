.setcpu "65816"
.segment "CODE"
.org $E040
map_control_0fe040:
    .byte $C1 ; same-value copy count/distance
