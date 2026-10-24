.setcpu "65816"
.segment "CODE"
.org $232E
map_control_0d232e:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
