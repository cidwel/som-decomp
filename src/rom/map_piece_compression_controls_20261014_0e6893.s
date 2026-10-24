.setcpu "65816"
.segment "CODE"
.org $6893
map_control_0e6893:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
