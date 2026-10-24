.setcpu "65816"
.segment "CODE"
.org $7DB4
map_control_0e7db4:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
