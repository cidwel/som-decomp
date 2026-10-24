.setcpu "65816"
.segment "CODE"
.org $909E
map_control_0c909e:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
