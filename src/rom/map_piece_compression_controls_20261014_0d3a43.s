.setcpu "65816"
.segment "CODE"
.org $3A43
map_control_0d3a43:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
