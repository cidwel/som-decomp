.setcpu "65816"
.segment "CODE"
.org $2CDF
map_control_0e2cdf:
    .byte $E7 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
