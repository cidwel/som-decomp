.setcpu "65816"
.segment "CODE"
.org $8574
map_control_0f8574:
    .byte $E7 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
