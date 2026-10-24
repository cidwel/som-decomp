.setcpu "65816"
.segment "CODE"
.org $3517
map_control_0f3517:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
