.setcpu "65816"
.segment "CODE"
.org $4925
map_control_0f4925:
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
