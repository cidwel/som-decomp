.setcpu "65816"
.segment "CODE"
.org $73F2
map_control_0c73f2:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $9A ; row-distance/count
    .byte $C6 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $DA ; same-value copy count/distance
