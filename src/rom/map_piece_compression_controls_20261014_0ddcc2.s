.setcpu "65816"
.segment "CODE"
.org $DCC2
map_control_0ddcc2:
    .byte $C6 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
