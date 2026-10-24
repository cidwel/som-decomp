.setcpu "65816"
.segment "CODE"
.org $2FED
map_control_0e2fed:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
