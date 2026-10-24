.setcpu "65816"
.segment "CODE"
.org $682F
map_control_0e682f:
    .byte $E6 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
