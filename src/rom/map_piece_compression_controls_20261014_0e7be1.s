.setcpu "65816"
.segment "CODE"
.org $7BE1
map_control_0e7be1:
    .byte $E7 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
