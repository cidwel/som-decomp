.setcpu "65816"
.segment "CODE"
.org $FA2F
map_control_0efa2f:
    .byte $E0 ; previous-row copy escape
    .byte $B0 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
