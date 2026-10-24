.setcpu "65816"
.segment "CODE"
.org $B8FC
map_control_0db8fc:
    .byte $CD ; same-value copy count/distance
