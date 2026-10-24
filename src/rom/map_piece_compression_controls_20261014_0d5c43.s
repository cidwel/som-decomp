.setcpu "65816"
.segment "CODE"
.org $5C43
map_control_0d5c43:
    .byte $C1 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
