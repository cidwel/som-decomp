.setcpu "65816"
.segment "CODE"
.org $1557
map_control_0f1557:
    .byte $E3 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
