.setcpu "65816"
.segment "CODE"
.org $B8AA
map_control_0fb8aa:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $46 ; row-distance/count
