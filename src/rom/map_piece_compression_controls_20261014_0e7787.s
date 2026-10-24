.setcpu "65816"
.segment "CODE"
.org $7787
map_control_0e7787:
    .byte $E6 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
