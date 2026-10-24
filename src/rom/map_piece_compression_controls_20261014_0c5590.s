.setcpu "65816"
.segment "CODE"
.org $5590
map_control_0c5590:
    .byte $C5 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
