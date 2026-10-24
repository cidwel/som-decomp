.setcpu "65816"
.segment "CODE"
.org $F3FF
map_control_0ef3ff:
    .byte $E0 ; previous-row copy escape
    .byte $BC ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $4A ; row-distance/count
