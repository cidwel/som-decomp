.setcpu "65816"
.segment "CODE"
.org $FCB4
map_control_0efcb4:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
