.setcpu "65816"
.segment "CODE"
.org $2605
map_control_0e2605:
    .byte $E3 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
