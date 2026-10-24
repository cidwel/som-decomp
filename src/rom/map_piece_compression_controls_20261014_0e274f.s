.setcpu "65816"
.segment "CODE"
.org $274F
map_control_0e274f:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
