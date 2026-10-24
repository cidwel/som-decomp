.setcpu "65816"
.segment "CODE"
.org $7770
map_control_0e7770:
    .byte $E6 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
