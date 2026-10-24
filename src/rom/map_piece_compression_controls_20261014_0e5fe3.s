.setcpu "65816"
.segment "CODE"
.org $5FE3
map_control_0e5fe3:
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
    .byte $F1 ; progressive-copy count
