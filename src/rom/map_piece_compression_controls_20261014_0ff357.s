.setcpu "65816"
.segment "CODE"
.org $F357
map_control_0ff357:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $38 ; row-distance/count
