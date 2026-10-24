.setcpu "65816"
.segment "CODE"
.org $7383
map_control_0c7383:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
