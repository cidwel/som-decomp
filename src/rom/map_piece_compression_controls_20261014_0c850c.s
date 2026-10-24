.setcpu "65816"
.segment "CODE"
.org $850C
map_control_0c850c:
    .byte $E2 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $B5 ; row-distance/count
