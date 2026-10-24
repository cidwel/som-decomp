.setcpu "65816"
.segment "CODE"
.org $9450
map_control_0e9450:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
