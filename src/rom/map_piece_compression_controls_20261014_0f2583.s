.setcpu "65816"
.segment "CODE"
.org $2583
map_control_0f2583:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
