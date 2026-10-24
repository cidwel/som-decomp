.setcpu "65816"
.segment "CODE"
.org $F42B
map_control_0ef42b:
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
