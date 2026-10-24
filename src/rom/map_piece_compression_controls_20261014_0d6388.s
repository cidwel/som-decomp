.setcpu "65816"
.segment "CODE"
.org $6388
map_control_0d6388:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
