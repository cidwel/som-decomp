.setcpu "65816"
.segment "CODE"
.org $C113
map_control_0dc113:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
