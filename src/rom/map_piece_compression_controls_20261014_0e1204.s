.setcpu "65816"
.segment "CODE"
.org $1204
map_control_0e1204:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
