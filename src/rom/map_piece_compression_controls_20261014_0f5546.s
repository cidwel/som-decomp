.setcpu "65816"
.segment "CODE"
.org $5546
map_control_0f5546:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $C9 ; same-value copy count/distance
