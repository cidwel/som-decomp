.setcpu "65816"
.segment "CODE"
.org $760C
map_control_0c760c:
    .byte $E7 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $51 ; row-distance/count
