.setcpu "65816"
.segment "CODE"
.org $93B1
map_control_0e93b1:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $D6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
