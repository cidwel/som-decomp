.setcpu "65816"
.segment "CODE"
.org $75E2
map_control_0c75e2:
    .byte $D9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
