.setcpu "65816"
.segment "CODE"
.org $D377
map_control_0fd377:
    .byte $E2 ; previous-row copy count
    .byte $DB ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $D9 ; same-value copy count/distance
