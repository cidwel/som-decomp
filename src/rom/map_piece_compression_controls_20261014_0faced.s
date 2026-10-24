.setcpu "65816"
.segment "CODE"
.org $ACED
map_control_0faced:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
