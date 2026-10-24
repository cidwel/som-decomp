.setcpu "65816"
.segment "CODE"
.org $38B6
map_control_0e38b6:
    .byte $C2 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
