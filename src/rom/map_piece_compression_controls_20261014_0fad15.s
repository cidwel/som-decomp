.setcpu "65816"
.segment "CODE"
.org $AD15
map_control_0fad15:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
