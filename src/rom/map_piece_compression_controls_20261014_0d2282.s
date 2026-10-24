.setcpu "65816"
.segment "CODE"
.org $2282
map_control_0d2282:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
