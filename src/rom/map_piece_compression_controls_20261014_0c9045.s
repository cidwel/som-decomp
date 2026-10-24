.setcpu "65816"
.segment "CODE"
.org $9045
map_control_0c9045:
    .byte $E2 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
