.setcpu "65816"
.segment "CODE"
.org $334F
map_control_0f334f:
    .byte $C2 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
