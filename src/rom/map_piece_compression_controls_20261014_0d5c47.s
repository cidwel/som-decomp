.setcpu "65816"
.segment "CODE"
.org $5C47
map_control_0d5c47:
    .byte $C7 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
