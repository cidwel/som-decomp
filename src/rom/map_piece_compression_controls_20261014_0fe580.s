.setcpu "65816"
.segment "CODE"
.org $E580
map_control_0fe580:
    .byte $E2 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
