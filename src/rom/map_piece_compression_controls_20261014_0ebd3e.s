.setcpu "65816"
.segment "CODE"
.org $BD3E
map_control_0ebd3e:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
