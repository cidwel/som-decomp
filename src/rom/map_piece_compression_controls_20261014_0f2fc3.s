.setcpu "65816"
.segment "CODE"
.org $2FC3
map_control_0f2fc3:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
