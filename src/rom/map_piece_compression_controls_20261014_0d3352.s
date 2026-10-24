.setcpu "65816"
.segment "CODE"
.org $3352
map_control_0d3352:
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
