.setcpu "65816"
.segment "CODE"
.org $58A7
map_control_0c58a7:
    .byte $C4 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
