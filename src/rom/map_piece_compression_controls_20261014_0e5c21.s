.setcpu "65816"
.segment "CODE"
.org $5C21
map_control_0e5c21:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
