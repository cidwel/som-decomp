.setcpu "65816"
.segment "CODE"
.org $7CDF
map_control_0d7cdf:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
