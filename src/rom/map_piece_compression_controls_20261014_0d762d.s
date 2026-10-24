.setcpu "65816"
.segment "CODE"
.org $762D
map_control_0d762d:
    .byte $E0 ; previous-row copy escape
    .byte $B6 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
