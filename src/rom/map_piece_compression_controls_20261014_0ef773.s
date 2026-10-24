.setcpu "65816"
.segment "CODE"
.org $F773
map_control_0ef773:
    .byte $E2 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
