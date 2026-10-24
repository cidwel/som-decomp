.setcpu "65816"
.segment "CODE"
.org $B2EE
map_control_0db2ee:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $C7 ; same-value copy count/distance
