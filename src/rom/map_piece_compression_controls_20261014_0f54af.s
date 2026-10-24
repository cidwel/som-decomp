.setcpu "65816"
.segment "CODE"
.org $54AF
map_control_0f54af:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
