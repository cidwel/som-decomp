.setcpu "65816"
.segment "CODE"
.org $3BA4
map_control_0d3ba4:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
