.setcpu "65816"
.segment "CODE"
.org $7AEA
map_control_0f7aea:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
