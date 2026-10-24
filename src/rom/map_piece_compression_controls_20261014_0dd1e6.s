.setcpu "65816"
.segment "CODE"
.org $D1E6
map_control_0dd1e6:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
