.setcpu "65816"
.segment "CODE"
.org $EA3F
map_control_0dea3f:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C1 ; same-value copy count/distance
