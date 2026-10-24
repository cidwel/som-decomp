.setcpu "65816"
.segment "CODE"
.org $BD3F
map_control_0fbd3f:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $37 ; row-distance/count
