.setcpu "65816"
.segment "CODE"
.org $F24D
map_control_0cf24d:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
