.setcpu "65816"
.segment "CODE"
.org $84D7
map_control_0f84d7:
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
