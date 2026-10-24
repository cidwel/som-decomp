.setcpu "65816"
.segment "CODE"
.org $1524
map_control_0f1524:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
