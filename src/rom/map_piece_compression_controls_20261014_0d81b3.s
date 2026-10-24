.setcpu "65816"
.segment "CODE"
.org $81B3
map_control_0d81b3:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
