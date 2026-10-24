.setcpu "65816"
.segment "CODE"
.org $74BC
map_control_0f74bc:
    .byte $E7 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
