.setcpu "65816"
.segment "CODE"
.org $7C48
map_control_0c7c48:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $43 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $4F ; row-distance/count
