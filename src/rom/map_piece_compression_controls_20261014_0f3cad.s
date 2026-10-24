.setcpu "65816"
.segment "CODE"
.org $3CAD
map_control_0f3cad:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
