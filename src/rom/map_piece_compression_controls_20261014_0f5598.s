.setcpu "65816"
.segment "CODE"
.org $5598
map_control_0f5598:
    .byte $E1 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
