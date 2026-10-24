.setcpu "65816"
.segment "CODE"
.org $E4C3
map_control_0de4c3:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
