.setcpu "65816"
.segment "CODE"
.org $024F
map_control_0f024f:
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
    .byte $E2 ; previous-row copy count
