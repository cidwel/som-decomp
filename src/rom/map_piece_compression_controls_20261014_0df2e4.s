.setcpu "65816"
.segment "CODE"
.org $F2E4
map_control_0df2e4:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
