.setcpu "65816"
.segment "CODE"
.org $9B7D
map_control_0f9b7d:
    .byte $C1 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
