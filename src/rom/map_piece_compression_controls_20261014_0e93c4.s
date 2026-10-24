.setcpu "65816"
.segment "CODE"
.org $93C4
map_control_0e93c4:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
