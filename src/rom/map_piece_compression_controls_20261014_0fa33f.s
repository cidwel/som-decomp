.setcpu "65816"
.segment "CODE"
.org $A33F
map_control_0fa33f:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
