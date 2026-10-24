.setcpu "65816"
.segment "CODE"
.org $F564
map_control_0ef564:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
