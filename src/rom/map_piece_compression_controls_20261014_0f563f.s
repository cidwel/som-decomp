.setcpu "65816"
.segment "CODE"
.org $563F
map_control_0f563f:
    .byte $C4 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
