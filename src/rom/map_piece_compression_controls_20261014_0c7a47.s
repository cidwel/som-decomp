.setcpu "65816"
.segment "CODE"
.org $7A47
map_control_0c7a47:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
