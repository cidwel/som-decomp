.setcpu "65816"
.segment "CODE"
.org $373F
map_control_0e373f:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
