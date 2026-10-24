.setcpu "65816"
.segment "CODE"
.org $660B
map_control_0c660b:
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
