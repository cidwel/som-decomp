.setcpu "65816"
.segment "CODE"
.org $F44C
map_control_0df44c:
    .byte $C3 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
