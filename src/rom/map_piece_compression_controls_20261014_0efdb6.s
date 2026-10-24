.setcpu "65816"
.segment "CODE"
.org $FDB6
map_control_0efdb6:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
    .byte $F1 ; progressive-copy count
