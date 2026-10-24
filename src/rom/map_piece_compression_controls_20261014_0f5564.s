.setcpu "65816"
.segment "CODE"
.org $5564
map_control_0f5564:
    .byte $C4 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
