.setcpu "65816"
.segment "CODE"
.org $1312
map_control_0e1312:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $43 ; row-distance/count
