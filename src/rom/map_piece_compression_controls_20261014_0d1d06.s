.setcpu "65816"
.segment "CODE"
.org $1D06
map_control_0d1d06:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
