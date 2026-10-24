.setcpu "65816"
.segment "CODE"
.org $01CB
map_control_0e01cb:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
