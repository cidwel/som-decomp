.setcpu "65816"
.segment "CODE"
.org $1284
map_control_0c1284:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $4F ; row-distance/count
