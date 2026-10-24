.setcpu "65816"
.segment "CODE"
.org $71DD
map_control_0e71dd:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
