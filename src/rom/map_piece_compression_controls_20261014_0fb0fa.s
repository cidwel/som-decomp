.setcpu "65816"
.segment "CODE"
.org $B0FA
map_control_0fb0fa:
    .byte $D4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
