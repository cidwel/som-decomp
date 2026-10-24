.setcpu "65816"
.segment "CODE"
.org $5549
map_control_0d5549:
    .byte $E3 ; previous-row copy count
    .byte $C7 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
