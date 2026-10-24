.setcpu "65816"
.segment "CODE"
.org $7CA1
map_control_0c7ca1:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $B0 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
