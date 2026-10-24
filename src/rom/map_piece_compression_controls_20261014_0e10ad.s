.setcpu "65816"
.segment "CODE"
.org $10AD
map_control_0e10ad:
    .byte $C1 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
