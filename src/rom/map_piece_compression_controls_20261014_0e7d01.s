.setcpu "65816"
.segment "CODE"
.org $7D01
map_control_0e7d01:
    .byte $E6 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
