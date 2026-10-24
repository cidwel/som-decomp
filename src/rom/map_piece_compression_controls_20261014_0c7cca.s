.setcpu "65816"
.segment "CODE"
.org $7CCA
map_control_0c7cca:
    .byte $E0 ; previous-row copy escape
    .byte $B0 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
