.setcpu "65816"
.segment "CODE"
.org $DCD6
map_control_0ddcd6:
    .byte $E5 ; previous-row copy count
    .byte $CB ; same-value copy count/distance
