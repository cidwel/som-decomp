.setcpu "65816"
.segment "CODE"
.org $4C93
map_control_0f4c93:
    .byte $E0 ; previous-row copy escape
    .byte $B8 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
