.setcpu "65816"
.segment "CODE"
.org $8BAD
map_control_0e8bad:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
