.setcpu "65816"
.segment "CODE"
.org $B985
map_control_0eb985:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
