.setcpu "65816"
.segment "CODE"
.org $2B70
map_control_0d2b70:
    .byte $E0 ; previous-row copy escape
    .byte $9D ; row-distance/count
    .byte $C2 ; same-value copy count/distance
