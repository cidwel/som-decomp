.setcpu "65816"
.segment "CODE"
.org $50B2
map_control_0e50b2:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
