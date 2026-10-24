.setcpu "65816"
.segment "CODE"
.org $86E6
map_control_0d86e6:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $55 ; row-distance/count
