.setcpu "65816"
.segment "CODE"
.org $B76F
map_control_0db76f:
    .byte $C6 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
