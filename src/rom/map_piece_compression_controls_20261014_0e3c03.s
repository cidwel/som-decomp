.setcpu "65816"
.segment "CODE"
.org $3C03
map_control_0e3c03:
    .byte $CD ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
