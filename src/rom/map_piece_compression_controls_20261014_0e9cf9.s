.setcpu "65816"
.segment "CODE"
.org $9CF9
map_control_0e9cf9:
    .byte $C4 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
