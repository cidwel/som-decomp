.setcpu "65816"
.segment "CODE"
.org $4421
map_control_0c4421:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
