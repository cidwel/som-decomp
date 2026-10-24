.setcpu "65816"
.segment "CODE"
.org $7AE6
map_control_0e7ae6:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
