.setcpu "65816"
.segment "CODE"
.org $1432
map_control_0e1432:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
