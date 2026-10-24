.setcpu "65816"
.segment "CODE"
.org $A226
map_control_0ea226:
    .byte $E2 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
