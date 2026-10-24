.setcpu "65816"
.segment "CODE"
.org $8518
map_control_0e8518:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
