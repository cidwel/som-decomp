.setcpu "65816"
.segment "CODE"
.org $FD02
map_control_0dfd02:
    .byte $E1 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
