.setcpu "65816"
.segment "CODE"
.org $7DF9
map_control_0e7df9:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
