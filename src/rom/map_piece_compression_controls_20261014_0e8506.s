.setcpu "65816"
.segment "CODE"
.org $8506
map_control_0e8506:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
