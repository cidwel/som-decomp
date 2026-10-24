.setcpu "65816"
.segment "CODE"
.org $EA15
map_control_0dea15:
    .byte $C5 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
