.setcpu "65816"
.segment "CODE"
.org $2A1D
map_control_0e2a1d:
    .byte $E3 ; previous-row copy count
    .byte $C7 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
