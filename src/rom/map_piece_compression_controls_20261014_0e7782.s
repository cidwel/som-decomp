.setcpu "65816"
.segment "CODE"
.org $7782
map_control_0e7782:
    .byte $E6 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
