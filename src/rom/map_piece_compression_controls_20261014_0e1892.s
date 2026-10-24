.setcpu "65816"
.segment "CODE"
.org $1892
map_control_0e1892:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
