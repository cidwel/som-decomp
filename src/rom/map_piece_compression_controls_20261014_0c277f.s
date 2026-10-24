.setcpu "65816"
.segment "CODE"
.org $277F
map_control_0c277f:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
    .byte $C1 ; same-value copy count/distance
