.setcpu "65816"
.segment "CODE"
.org $C7D2
map_control_0fc7d2:
    .byte $C1 ; same-value copy count/distance
    .byte $DB ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
