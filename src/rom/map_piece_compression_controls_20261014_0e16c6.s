.setcpu "65816"
.segment "CODE"
.org $16C6
map_control_0e16c6:
    .byte $C1 ; same-value copy count/distance
    .byte $D9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
