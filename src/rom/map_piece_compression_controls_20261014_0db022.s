.setcpu "65816"
.segment "CODE"
.org $B022
map_control_0db022:
    .byte $CD ; same-value copy count/distance
