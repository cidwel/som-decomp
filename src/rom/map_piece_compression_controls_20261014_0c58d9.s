.setcpu "65816"
.segment "CODE"
.org $58D9
map_control_0c58d9:
    .byte $E2 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
