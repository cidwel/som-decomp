.setcpu "65816"
.segment "CODE"
.org $5D57
map_control_0d5d57:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
