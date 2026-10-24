.setcpu "65816"
.segment "CODE"
.org $C253
map_control_0ec253:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $C1 ; same-value copy count/distance
