.setcpu "65816"
.segment "CODE"
.org $1CF2
map_control_0e1cf2:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
