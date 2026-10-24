.setcpu "65816"
.segment "CODE"
.org $FD48
map_control_0dfd48:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
