.setcpu "65816"
.segment "CODE"
.org $79BC
map_control_0d79bc:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $A8 ; row-distance/count
