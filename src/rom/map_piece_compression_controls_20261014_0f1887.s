.setcpu "65816"
.segment "CODE"
.org $1887
map_control_0f1887:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
