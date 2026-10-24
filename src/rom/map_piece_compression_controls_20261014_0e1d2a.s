.setcpu "65816"
.segment "CODE"
.org $1D2A
map_control_0e1d2a:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
