.setcpu "65816"
.segment "CODE"
.org $ADD4
map_control_0fadd4:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
