.setcpu "65816"
.segment "CODE"
.org $6DD9
map_control_0d6dd9:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
