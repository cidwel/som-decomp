.setcpu "65816"
.segment "CODE"
.org $CD85
map_control_0fcd85:
    .byte $C1 ; same-value copy count/distance
