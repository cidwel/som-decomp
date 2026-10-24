.setcpu "65816"
.segment "CODE"
.org $3605
map_control_0e3605:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
