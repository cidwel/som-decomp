.setcpu "65816"
.segment "CODE"
.org $FE93
map_control_0efe93:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
