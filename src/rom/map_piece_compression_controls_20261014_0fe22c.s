.setcpu "65816"
.segment "CODE"
.org $E22C
map_control_0fe22c:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
