.setcpu "65816"
.segment "CODE"
.org $11AB
map_control_0e11ab:
    .byte $CB ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
