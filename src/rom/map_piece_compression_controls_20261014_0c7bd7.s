.setcpu "65816"
.segment "CODE"
.org $7BD7
map_control_0c7bd7:
    .byte $E0 ; previous-row copy escape
    .byte $39 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
