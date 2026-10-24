.setcpu "65816"
.segment "CODE"
.org $1079
map_control_0c1079:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
