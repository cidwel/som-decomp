.setcpu "65816"
.segment "CODE"
.org $84A9
map_control_0d84a9:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
