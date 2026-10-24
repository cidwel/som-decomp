.setcpu "65816"
.segment "CODE"
.org $1709
map_control_0f1709:
    .byte $CD ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
