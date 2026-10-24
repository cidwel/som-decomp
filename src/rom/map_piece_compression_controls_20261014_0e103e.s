.setcpu "65816"
.segment "CODE"
.org $103E
map_control_0e103e:
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
