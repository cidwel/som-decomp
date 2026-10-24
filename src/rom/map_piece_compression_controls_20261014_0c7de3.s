.setcpu "65816"
.segment "CODE"
.org $7DE3
map_control_0c7de3:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
