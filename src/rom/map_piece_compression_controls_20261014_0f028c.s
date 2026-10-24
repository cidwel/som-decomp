.setcpu "65816"
.segment "CODE"
.org $028C
map_control_0f028c:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
