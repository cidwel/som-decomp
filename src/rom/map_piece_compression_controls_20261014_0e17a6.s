.setcpu "65816"
.segment "CODE"
.org $17A6
map_control_0e17a6:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
