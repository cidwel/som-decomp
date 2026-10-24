.setcpu "65816"
.segment "CODE"
.org $6322
map_control_0c6322:
    .byte $C9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
