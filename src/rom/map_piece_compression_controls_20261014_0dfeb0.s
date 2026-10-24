.setcpu "65816"
.segment "CODE"
.org $FEB0
map_control_0dfeb0:
    .byte $C3 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
