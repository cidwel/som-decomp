.setcpu "65816"
.segment "CODE"
.org $7D13
map_control_0e7d13:
    .byte $E6 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
