.setcpu "65816"
.segment "CODE"
.org $F1C4
map_control_0ef1c4:
    .byte $E0 ; previous-row copy escape
    .byte $AA ; row-distance/count
    .byte $C4 ; same-value copy count/distance
