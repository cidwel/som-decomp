.setcpu "65816"
.segment "CODE"
.org $3ED9
map_control_0d3ed9:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
