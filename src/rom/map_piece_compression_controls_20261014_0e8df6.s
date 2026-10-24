.setcpu "65816"
.segment "CODE"
.org $8DF6
map_control_0e8df6:
    .byte $E2 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
