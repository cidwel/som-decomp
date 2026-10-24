.setcpu "65816"
.segment "CODE"
.org $3C48
map_control_0e3c48:
    .byte $E1 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
