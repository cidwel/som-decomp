.setcpu "65816"
.segment "CODE"
.org $53AC
map_control_0d53ac:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
