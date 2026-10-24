.setcpu "65816"
.segment "CODE"
.org $457F
map_control_0e457f:
    .byte $E5 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
