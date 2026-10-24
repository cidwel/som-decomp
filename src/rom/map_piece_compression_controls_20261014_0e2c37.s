.setcpu "65816"
.segment "CODE"
.org $2C37
map_control_0e2c37:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
