.setcpu "65816"
.segment "CODE"
.org $946C
map_control_0e946c:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
