.setcpu "65816"
.segment "CODE"
.org $9624
map_control_0f9624:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
