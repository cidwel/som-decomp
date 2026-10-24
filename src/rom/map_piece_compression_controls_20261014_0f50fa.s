.setcpu "65816"
.segment "CODE"
.org $50FA
map_control_0f50fa:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
