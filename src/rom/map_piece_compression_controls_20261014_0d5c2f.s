.setcpu "65816"
.segment "CODE"
.org $5C2F
map_control_0d5c2f:
    .byte $C2 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
