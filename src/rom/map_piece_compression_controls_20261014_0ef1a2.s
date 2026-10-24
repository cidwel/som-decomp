.setcpu "65816"
.segment "CODE"
.org $F1A2
map_control_0ef1a2:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
