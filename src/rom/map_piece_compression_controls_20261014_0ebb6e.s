.setcpu "65816"
.segment "CODE"
.org $BB6E
map_control_0ebb6e:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
