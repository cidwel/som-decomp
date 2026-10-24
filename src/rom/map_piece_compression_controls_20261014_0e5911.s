.setcpu "65816"
.segment "CODE"
.org $5911
map_control_0e5911:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $61 ; row-distance/count
