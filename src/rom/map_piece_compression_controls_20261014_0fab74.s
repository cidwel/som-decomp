.setcpu "65816"
.segment "CODE"
.org $AB74
map_control_0fab74:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
