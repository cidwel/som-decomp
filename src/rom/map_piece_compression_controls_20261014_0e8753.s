.setcpu "65816"
.segment "CODE"
.org $8753
map_control_0e8753:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
