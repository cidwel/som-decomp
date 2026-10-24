.setcpu "65816"
.segment "CODE"
.org $A7CC
map_control_0ea7cc:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $3E ; row-distance/count
