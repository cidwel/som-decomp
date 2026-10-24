.setcpu "65816"
.segment "CODE"
.org $C500
map_control_0dc500:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
