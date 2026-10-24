.setcpu "65816"
.segment "CODE"
.org $115E
map_control_0e115e:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
