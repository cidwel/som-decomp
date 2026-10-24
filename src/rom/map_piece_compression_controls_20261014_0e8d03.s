.setcpu "65816"
.segment "CODE"
.org $8D03
map_control_0e8d03:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
