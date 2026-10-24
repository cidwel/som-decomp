.setcpu "65816"
.segment "CODE"
.org $1BA5
map_control_0d1ba5:
    .byte $E1 ; previous-row copy count
    .byte $DF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
