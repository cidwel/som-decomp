.setcpu "65816"
.segment "CODE"
.org $3FEF
map_control_0d3fef:
    .byte $E2 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
