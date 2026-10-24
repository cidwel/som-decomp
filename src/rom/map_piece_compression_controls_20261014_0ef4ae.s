.setcpu "65816"
.segment "CODE"
.org $F4AE
map_control_0ef4ae:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $BC ; row-distance/count
    .byte $E1 ; previous-row copy count
