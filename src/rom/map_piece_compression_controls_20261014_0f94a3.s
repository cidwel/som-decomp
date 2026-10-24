.setcpu "65816"
.segment "CODE"
.org $94A3
map_control_0f94a3:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D2 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
