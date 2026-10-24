.setcpu "65816"
.segment "CODE"
.org $0CF7
map_control_0e0cf7:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
