.setcpu "65816"
.segment "CODE"
.org $F543
map_control_0ef543:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
