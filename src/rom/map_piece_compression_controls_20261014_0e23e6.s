.setcpu "65816"
.segment "CODE"
.org $23E6
map_control_0e23e6:
    .byte $C4 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
