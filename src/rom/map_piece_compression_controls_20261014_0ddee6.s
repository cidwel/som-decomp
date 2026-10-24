.setcpu "65816"
.segment "CODE"
.org $DEE6
map_control_0ddee6:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
    .byte $C3 ; same-value copy count/distance
