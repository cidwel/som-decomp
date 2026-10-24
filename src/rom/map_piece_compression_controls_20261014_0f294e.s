.setcpu "65816"
.segment "CODE"
.org $294E
map_control_0f294e:
    .byte $E1 ; previous-row copy count
    .byte $DA ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
