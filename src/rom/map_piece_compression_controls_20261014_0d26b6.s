.setcpu "65816"
.segment "CODE"
.org $26B6
map_control_0d26b6:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
