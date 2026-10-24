.setcpu "65816"
.segment "CODE"
.org $6FDD
map_control_0e6fdd:
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
