.setcpu "65816"
.segment "CODE"
.org $5A13
map_control_0e5a13:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
