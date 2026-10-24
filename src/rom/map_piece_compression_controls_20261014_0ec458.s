.setcpu "65816"
.segment "CODE"
.org $C458
map_control_0ec458:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
