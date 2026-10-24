.setcpu "65816"
.segment "CODE"
.org $F29F
map_control_0ef29f:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
