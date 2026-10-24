.setcpu "65816"
.segment "CODE"
.org $55E6
map_control_0d55e6:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
