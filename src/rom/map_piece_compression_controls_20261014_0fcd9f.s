.setcpu "65816"
.segment "CODE"
.org $CD9F
map_control_0fcd9f:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
