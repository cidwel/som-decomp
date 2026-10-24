.setcpu "65816"
.segment "CODE"
.org $BA83
map_control_0fba83:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
