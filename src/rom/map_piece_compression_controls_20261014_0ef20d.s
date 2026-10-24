.setcpu "65816"
.segment "CODE"
.org $F20D
map_control_0ef20d:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
