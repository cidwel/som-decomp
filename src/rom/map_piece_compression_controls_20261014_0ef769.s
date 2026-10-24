.setcpu "65816"
.segment "CODE"
.org $F769
map_control_0ef769:
    .byte $D9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count
