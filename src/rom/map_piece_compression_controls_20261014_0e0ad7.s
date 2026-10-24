.setcpu "65816"
.segment "CODE"
.org $0AD7
map_control_0e0ad7:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $A8 ; row-distance/count
