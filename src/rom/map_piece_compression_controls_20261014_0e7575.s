.setcpu "65816"
.segment "CODE"
.org $7575
map_control_0e7575:
    .byte $E6 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
