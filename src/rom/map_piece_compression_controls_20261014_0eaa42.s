.setcpu "65816"
.segment "CODE"
.org $AA42
map_control_0eaa42:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $E5 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
