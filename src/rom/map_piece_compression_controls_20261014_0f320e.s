.setcpu "65816"
.segment "CODE"
.org $320E
map_control_0f320e:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
