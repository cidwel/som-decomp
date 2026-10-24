.setcpu "65816"
.segment "CODE"
.org $7A29
map_control_0e7a29:
    .byte $E2 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
