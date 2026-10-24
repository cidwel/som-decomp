.setcpu "65816"
.segment "CODE"
.org $7552
map_control_0f7552:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $CD ; same-value copy count/distance
